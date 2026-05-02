// Function : FUN_400fe5f0
// Address  : 0x400fe5f0
// Size     : 33 bytes


undefined4 FUN_400fe5f0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 4) == 0x3ff42000) && (0x51fff < param_2 + 0xc0052000U)) {
    uVar1 = 0;
  }
  return uVar1;
}

