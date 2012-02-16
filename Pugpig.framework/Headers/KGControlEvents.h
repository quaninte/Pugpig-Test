//
//  KGControlEvents.h
//  Pugpig
//
//  Copyright (c) 2011, Kaldor Holdings Ltd.
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this list of
//  conditions and the following disclaimer. Redistributions in binary form must reproduce
//  the above copyright notice, this list of conditions and the following disclaimer in
//  the documentation and/or other materials provided with the distribution.
//  Neither the name of pugpig nor the names of its contributors may be
//  used to endorse or promote products derived from this software without specific prior
//  written permission.
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//  SUCH DAMAGE.
//

// Note that the bits reserved for applications in the UIControlEvents enum 
// only give us bits 24 to 27 which is a bit stingy. As a result we've had to 
// steal another 4 bits in the unreserved range 20 to 23. Hopefully this
// should still be safe.
typedef enum {
  KGControlEventDataSourceWillLoadForeground = (1 << 20),
  KGControlEventDataSourceWillLoadBackground = (1 << 21),
  KGControlEventDataSourceDidLoadForeground  = (1 << 22),
  KGControlEventDataSourceDidLoadBackground  = (1 << 23),
  KGControlEventContentLoadFinished          = (1 << 24),
  KGControlEventContentSnapshotFinished      = (1 << 25),
  KGControlEventContentLayoutChanged         = (1 << 26),
  KGControlEventContentSizeChanged           = (1 << 27), 
} KGControlEvents;
