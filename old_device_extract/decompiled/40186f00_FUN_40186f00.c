// Function : FUN_40186f00
// Address  : 0x40186f00
// Size     : 50 bytes


bool FUN_40186f00(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0x10;
  local_30 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,&local_30);
  bVar1 = (uStack_2c & 6) == 6;
  if (bVar1) {
    *param_3 = local_30;
  }
  return bVar1;
}

