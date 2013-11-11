<?php
/**
 * @file
 * sitenow_people.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sitenow_people_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function sitenow_people_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function sitenow_people_image_default_styles() {
  $styles = array();

  // Exported image style: people_grid.
  $styles['people_grid'] = array(
    'name' => 'people_grid',
    'label' => 'People Grid',
    'effects' => array(
      11 => array(
        'label' => 'Reuse a Manual Crop selection',
        'help' => 'Reuse a crop selection from another Manual Crop enabled image style.',
        'effect callback' => 'manualcrop_reuse_effect',
        'form callback' => 'manualcrop_reuse_form',
        'summary theme' => 'manualcrop_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reusestyle' => 'crop_selection_rectangle_3-2',
          'style_name' => 'people_grid',
        ),
        'weight' => 0,
      ),
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 500,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: people_table.
  $styles['people_table'] = array(
    'name' => 'people_table',
    'label' => 'People Table',
    'effects' => array(
      13 => array(
        'label' => 'Reuse a Manual Crop selection',
        'help' => 'Reuse a crop selection from another Manual Crop enabled image style.',
        'effect callback' => 'manualcrop_reuse_effect',
        'form callback' => 'manualcrop_reuse_form',
        'summary theme' => 'manualcrop_reuse_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_reuse',
        'data' => array(
          'reusestyle' => 'crop_selection_rectangle_3-2',
          'style_name' => 'people_table',
        ),
        'weight' => 0,
      ),
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function sitenow_people_node_info() {
  $items = array(
    'people' => array(
      'name' => t('Person'),
      'base' => 'node_content',
      'description' => t('Use the <em>person</em> content type to create a directory of faculty, staff, and students on your site. This is <strong>not</strong> used to give users access to your site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The title will be constructed from the first name and last name fields, e.g. Jane Doe. A middle name or initial can be used after the first name. The photo field will be used as a thumbnail on the <a href="/people">people page</a>. See the <a href="/admin/apps/sitenow/sitenow_people/configure">demo content</a> for an example.'),
    ),
  );
  return $items;
}
