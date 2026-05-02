// Function : FUN_400fe73c
// Address  : 0x400fe73c
// Size     : 29 bytes


uint FUN_400fe73c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 < 0x40)) {
    uVar1 = (uint)(byte)(&DAT_3ffbdd4e)[param_2 * 3];
  }
  return uVar1;
}

