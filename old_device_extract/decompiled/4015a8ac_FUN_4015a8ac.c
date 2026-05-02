// Function : FUN_4015a8ac
// Address  : 0x4015a8ac
// Size     : 71 bytes


undefined4
FUN_4015a8ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5,undefined1 param_6,uint param_7)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 4;
  uVar2 = uVar1;
  if (((((param_7 & 0x20) == 0) && ((param_7 & 0x10) != 0)) && (uVar2 = *param_4 - 1, 1 < uVar2)) &&
     (uVar2 = uVar1, *param_4 == 0)) {
    uVar2 = 1;
  }
  if (((param_7 & 0x10) != 0) && (uVar2 == 0)) {
    memw();
    FUN_4015fa60(param_1,param_2,param_4,param_3,0,param_5,param_6);
    return 0;
  }
  return 0xffffffff;
}

