#! /usr/bin/env python
# encoding: utf-8
# Thomas Nagy, 2006-2010 (ita)

# the following two variables are used by the target "waf dist"
VERSION='0.0.1'
APPNAME='LoliLeetCode'

# these variables are mandatory ('/' are converted automatically)
top = '.'
out = 'build'

def options(opt):
	opt.load('compiler_cxx')

def configure(conf):
	conf.load('compiler_cxx')
#	conf.check(header_name='stdio.h', features='cxx cxxprogram', mandatory=False)

def build(bld):
     for app in bld.path.ant_glob('*.cpp'):
        bld(features=['cxx', 'cxxprogram'],
            target = '%s' % (str(app.change_ext('','.cpp'))),
            cxxflags = ['-std=c++0x'],
            source = app,
            ) 
