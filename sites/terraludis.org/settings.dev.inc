<?php

// Disable Analytics
$conf['googleanalytics_account'] = '';

// Disable caching
$conf['preprocess_css'] = FALSE;
$conf['preprocess_js'] = FALSE;
$conf['block_cache'] = FALSE;
$conf['cache'] = FALSE;
$conf['cache_lifetime'] = 0;
$conf['page_cache_maximum_age'] = 0;

// Enable mails debug mode
$conf['feature_config_mails_debug'] = TRUE;
$conf['feature_config_mails_debug_mail'] = 'debug-tl+to@duael.fr';
$conf['feature_config_mails_debug_from'] = 'debug-tl+from@duael.fr';
$conf['feature_config_mails_debug_send'] = FALSE;

// Disable honeypot time limit
$conf['honeypot_time_limit'] = 0;

// Rebuild theme registry on each page
$conf['devel_rebuild_theme_registry'] = TRUE;

// Use uncompressed jQuery
$conf['jquery_update_compression_type'] = 'none';

// Enable all errors.
$conf['error_level'] = 2;