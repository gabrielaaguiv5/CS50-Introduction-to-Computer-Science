chrome.runtime.sendMessage({ action: 'captureScreenshots' });

chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
  if (message.action === 'screenshotUrls') {
    const tabList = document.getElementById('tabList');
    message.urls.forEach((url, index) => {
      const listItem = document.createElement('li');
      const link = document.createElement('a');
      const image = document.createElement('img');
      image.src = url;
      link.href = '#'; // You can set this to the tab's actual URL
      link.appendChild(image);
      listItem.appendChild(link);
      tabList.appendChild(listItem);
    });
  }
});