{
  'targets': [
    {
      'target_name': 'node-qb',
      'sources': [ 'src/node-qb.cpp',  ],
      'configurations': {
        'Release': {
          'msvs_settings': {
            'VCCLCompilerTool': {
              'RuntimeLibrary': -1, 
              'RuntimeTypeInfo': -1, 
              'BasicRuntimeChecks': -1,
              'ExceptionHandling': '0',
              'AdditionalOptions': [ '/clr', '/wd4506' ] 
            },
            'VCLinkerTool': {
              'AdditionalOptions': [ '/ignore:4248' ]
            }
          }
        },
		'Debug': {
          'msvs_settings': {
            'VCCLCompilerTool': {
              'RuntimeLibrary': -1, 
              'RuntimeTypeInfo': -1, 
              'BasicRuntimeChecks': -1,
              'ExceptionHandling': '0',
              'AdditionalOptions': [ '/clr', '/wd4506' ] 
            },
            'VCLinkerTool': {
              'AdditionalOptions': [ '/ignore:4248' ]
            }
          }
        }
        }
      }

  ]
}