module.exports = function (grunt) {

  /**
   * Project configuration.
   */
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    paths: {
      drupal: '../httpdocs',
      src: '.',
      theme: '<%= paths.drupal %>/sites/all/themes/custom/parliamentwatch',
      sass: '<%= paths.src %>/scss',
      css: '<%= paths.theme %>/css',
      js: '<%= paths.theme %>/js',
    },
    cssmin: {
      options: {
        compatibility: 'ie8',
        keepSpecialComments: '*',
        advanced: false
      },
      theme: {
        src: '<%= paths.css %>/theme.css',
        dest: '<%= paths.css %>/theme.min.css'
      }
    },
    sass: {
      theme: {
        options: {
          sourceMap: true,
          outputSourceFiles: true,
          sourceMapURL: 'theme.css.map',
          sourceMapFilename: '<%= paths.css %>/theme.css.map'
        },
        files: {
          '<%= paths.css %>/theme.css': '<%= paths.sass %>/theme.scss'
        }
      }
    },
    bowercopy: {
      contrib: {
        files: {
          '<%= paths.sass %>/bourbon': 'bourbon/app/assets/stylesheets',
          '<%= paths.sass %>/neat': 'neat/core',
          '<%= paths.sass %>/breakpoint': 'breakpoint-sass/stylesheets',
          '<%= paths.css %>/contrib/normalize.css': 'normalize-css/normalize.css',
          '<%= paths.css %>/contrib/select2.css': 'select2/dist/css/select2.css',
          '<%= paths.css %>/contrib/swiper.css': 'swiper/dist/css/swiper.css',
          '<%= paths.css %>/contrib/lightbox.min.css': 'lightbox/dist/css/lightbox.min.css',
          '<%= paths.js %>/contrib/typeahead.bundle.min.js': 'typeahead.js/dist/typeahead.bundle.min.js',
          '<%= paths.js %>/contrib/d3.min.js': 'd3/d3.min.js',
          '<%= paths.js %>/contrib/jquery.scrollTo.min.js': 'jquery.scrollTo/jquery.scrollTo.min.js',
          '<%= paths.js %>/contrib/jquery.hoverIntent.js': 'jquery-hoverintent/jquery.hoverIntent.js',
          '<%= paths.js %>/contrib/jquery.sticky-kit.min.js': 'sticky-kit/jquery.sticky-kit.min.js',
          '<%= paths.js %>/contrib/stupidtable.min.js': 'jquery-stupid-table/stupidtable.min.js',
          '<%= paths.js %>/contrib/swiper.min.js': 'swiper/dist/js/swiper.min.js',
          '<%= paths.js %>/contrib/maps/swiper.min.js.map': 'swiper/dist/js/maps/swiper.min.js.map',
          '<%= paths.js %>/contrib/lightbox.min.js': 'lightbox/dist/js/lightbox.min.js',
          '<%= paths.js %>/contrib/lightbox.min.map': 'lightbox/dist/js/lightbox.min.map',
          '<%= paths.js %>/contrib/select2.min.js': 'select2/dist/js/select2.min.js',
          '<%= paths.js %>/contrib/jquery.matchHeight-min.js': 'matchHeight/dist/jquery.matchHeight-min.js',
          '<%= paths.js %>/contrib/jquery.dynatable.js': 'dynatable/jquery.dynatable.js'
        }
      }
    },
    watch: {
      options: {
        spawn: false // add spawn option in watch task
      },
      sass: {
        files: '<%= paths.sass %>**/*.scss',
        tasks: ['sass', 'cssmin'],
        options: {
          livereload: true
        }
      }
    }
  });

  /**
   * Register tasks
   */
  grunt.loadNpmTasks('grunt-bower-just-install');
  grunt.loadNpmTasks('grunt-contrib-cssmin');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-bowercopy');
  grunt.loadNpmTasks('grunt-npm-install');

  /**
   * Grunt update task
   */
  grunt.registerTask('update', ['npm-install', 'bower_install']);
  grunt.registerTask('build', ['update', 'sass', 'bowercopy', 'cssmin']);
  grunt.registerTask('compile', ['sass', 'cssmin']);

};
