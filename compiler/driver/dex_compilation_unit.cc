/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "dex_compilation_unit.h"

#include "base/stringprintf.h"
#include "mirror/dex_cache.h"
#include "utils.h"

namespace art {

DexCompilationUnit::DexCompilationUnit(jobject class_loader,
                                       ClassLinker* class_linker,
                                       const DexFile& dex_file,
                                       const DexFile::CodeItem* code_item,
                                       uint16_t class_def_idx,
                                       uint32_t method_idx,
                                       uint32_t access_flags,
                                       const VerifiedMethod* verified_method,
                                       Handle<mirror::DexCache> dex_cache)
    : class_loader_(class_loader),
      class_linker_(class_linker),
      dex_file_(&dex_file),
      code_item_(code_item),
      class_def_idx_(class_def_idx),
      dex_method_idx_(method_idx),
      access_flags_(access_flags),
      verified_method_(verified_method),
      dex_cache_(dex_cache) {
}

const std::string& DexCompilationUnit::GetSymbol() {
  if (symbol_.empty()) {
    symbol_ = "dex_";
    symbol_ += MangleForJni(PrettyMethod(dex_method_idx_, *dex_file_));
  }
  return symbol_;
}

}  // namespace art
