chrome.tabs.query({}, tabs => {
    const tabList = document.getElementById('tabList');
    tabs.forEach(tab => {
      const listItem = document.createElement('li');
      const link = document.createElement('a');
      link.href = tab.url; // Set the link's href to the tab's URL
      link.textContent = tab.title;
      listItem.appendChild(link);
      tabList.appendChild(listItem);
    });
  });