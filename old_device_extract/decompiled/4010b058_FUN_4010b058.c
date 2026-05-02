// Function : FUN_4010b058
// Address  : 0x4010b058
// Size     : 32 bytes


undefined4 FUN_4010b058(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x12) {
    uVar1 = FUN_4010affc(**(undefined2 **)("do_memp_malloc_pool" + param_1 * 4 + 0xd));
  }
  return uVar1;
}

