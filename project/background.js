// background.js
chrome.tabs.query({}, tabs => {
    const tabList = document.getElementById('tabList');
    tabs.forEach(tab => {
      const listItem = document.createElement('li');
      listItem.textContent = tab.title;
      tabList.appendChild(listItem);
    });
  });
