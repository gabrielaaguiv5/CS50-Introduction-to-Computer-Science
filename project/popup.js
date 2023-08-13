chrome.tabs.query({}, tabs => {
    const tabList = document.getElementById('tabList');
    tabs.forEach(tab => {
      const listItem = document.createElement('li');
      const link = document.createElement('a');

      link.textContent = tab.title || tab.url;
      link.href = tab.url;
      link.target = '_blank'; // Open in a new tab

      listItem.appendChild(link);
      tabList.appendChild(listItem);
    });
  });