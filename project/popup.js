chrome.tabs.query({}, tabs => {
    const tabList = document.getElementById('tabList');
    tabs.forEach(tab => {
      const listItem = document.createElement('li');
      const link = document.createElement('a');

      link.textContent = tab.title || tab.url;
      link.href = `javascript:redirectToTab(${tab.id});`; // Use JavaScript function
      link.addEventListener('click', event => {
        event.preventDefault(); // Prevent default link behavior
      });

      listItem.appendChild(link);
      tabList.appendChild(listItem);
    });
  });

  function redirectToTab(tabId) {
    chrome.tabs.update(tabId, { active: true });
    window.close(); // Close the popup after redirecting
  }