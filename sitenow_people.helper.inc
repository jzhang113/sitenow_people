<?php

function sitenow_people_create_menu() {
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

function sitenow_people_delete_menu() {
     // remove menu link
     menu_link_delete(variable_get('sitenow_people_mlid'));
     menu_cache_clear_all(); 
     // remove variable
     variable_del('sitenow_people_mlid');  
  }