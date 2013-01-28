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

  global $base_url;

  // flush cache to assure all config got instantiated properly
  $form = array();

  // This is currently just to test the apps config integration
  $form['sitenow_people_config_group'] = array(
      '#type' => 'fieldset',
      '#title' => "Configuration Options for SiteNow People",
  );

  $form['sitenow_people_config_group']['sitenow_people_order_link'] = array(
    '#markup' => '<a href="' . $base_url . '/admin/apps/sitenow/app/sitenow_people/configure/order">Change order of people</a>',
  );

  return $form;
}

/*
 * Implements hook_form_FORM_ID_alter().
 */
function sitenow_people_form_apps_demo_content_form_alter(&$form, &$form_state, $form_id) {
  $app = $form['app']['#value']['machine_name'];
  if ($app === 'sitenow_people') {

    // If the SiteNowPeople migration has run and the sitenow_people_content
    // module is currently disabled, keep it that way.
    if(migration_log('SiteNowPeople') && !module_exists('sitenow_people_content')) {
      $form['demo_content_group']['demo_content_button']['#suffix'] = "Demo content has already been enabled for this site, the content is already available.";
      $form['demo_content_group']['demo_content_button']['#disabled'] = TRUE;
    }
  }
}
