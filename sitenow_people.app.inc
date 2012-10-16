<?php
/**
 * Implements hook_apps_app_info().
 */
function sitenow_people_apps_app_info() {
  return array(
    'configure form' => 'sitenow_people_apps_app_configure_form',
    'demo content module' => 'sitenow_people_content',
    //'status callback' => 'enterprise_blog_app_status',
    //'post install callback' => 'sitenow_people_app_post_install',
  );
}

/**
* Config form for SiteNow People App
*/
function sitenow_people_apps_app_configure_form($form, &$form_state) {
  // flush cache to assure all config got instantiated properly
  $form = array();
	
  // This is currently just to test the apps config integration
  $form['sitenow_people_config_group'] = array(
      '#type' => 'fieldset',
      '#title' => "Configuration Options for SiteNow People",
  );
  
  $form['sitenow_people_config_group']['sitenow_people_order_link'] = array(
    '#markup' => '<a href="/admin/apps/sitenow/app/sitenow_people/configure/order">Change order of people</a>',
  );
    
  return $form;
}

/**
* Post Install function for SiteNow People App
*/
/*function sitenow_people_app_post_install() {
  // check to see if module enabled
  if (module_exists('sitenow_people')) {
	// create menu item for sitenow_people panel page
    $item = array(
    'link_path' => drupal_get_normal_path('people'),
    'link_title' => 'People',
    'menu_name' => 'main-menu',
    );
  
    $mlid = menu_link_save($item);
    variable_set('sitenow_people_mlid', $mlid);
    menu_cache_clear_all(); 
  }
}*/