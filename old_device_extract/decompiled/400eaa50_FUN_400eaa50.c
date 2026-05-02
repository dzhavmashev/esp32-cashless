// Function : FUN_400eaa50
// Address  : 0x400eaa50
// Size     : 56 bytes


undefined4 FUN_400eaa50(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_4012b2e8(param_1 + 8,0);
  uVar2 = (*(code *)&LAB_401858c7_1)(param_1 + 8);
  if (((uVar1 & 0xffffff7f) != 0xffff9700) && ((int)uVar1 < 0)) {
    uVar2 = FUN_400e9fc8(uVar1,"sl_data",0x169);
  }
  return uVar2;
}

