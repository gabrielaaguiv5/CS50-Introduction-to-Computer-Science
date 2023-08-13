// Tabs Sorter by Gabriela Aguilar 2023 - Back End

chrome.tabs.query({currentWindow: true}, tabs =>
  {
  const tabList = document.getElementById('tabList');
  tabs.forEach(tab =>
    {
    const listItem = document.createElement('li');
    const link = document.createElement('a');

    link.textContent = tab.title || tab.url;
    link.href = '#'; // Set a placeholder href
    link.addEventListener('click', event => {
      event.preventDefault(); // Prevent default link behavior
      activateTab(tab.id);
    });

    listItem.appendChild(link);
    tabList.appendChild(listItem);
  });
});

function activateTab(tabId) {
  chrome.tabs.update(tabId, { active: true });
  window.close(); // Close the popup after activating the tab
}