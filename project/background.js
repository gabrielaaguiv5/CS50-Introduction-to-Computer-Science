// background.js
chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
    if (message.action === 'captureScreenshots') {
      chrome.tabs.query({}, tabs => {
        const screenshotUrls = [];
        const tabPromises = tabs.map(tab => {
          return new Promise(resolve => {
            chrome.tabs.captureVisibleTab(tab.windowId, { format: 'png' }, dataUrl => {
              screenshotUrls.push(dataUrl);
              resolve();
            });
          });
        });

        Promise.all(tabPromises).then(() => {
          chrome.runtime.sendMessage({ action: 'screenshotUrls', urls: screenshotUrls });
        });
      });
    }
  });