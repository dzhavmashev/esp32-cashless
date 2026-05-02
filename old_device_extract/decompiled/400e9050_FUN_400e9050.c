// Function : FUN_400e9050
// Address  : 0x400e9050
// Size     : 39 bytes


uint FUN_400e9050(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    param_3 = 0;
  }
  else {
    uVar1 = func_0x4008c024(param_2);
    if (uVar1 < param_3) {
      param_3 = uVar1 + 1;
    }
    func_0x4008b3d8(param_1,param_2,param_3);
  }
  return param_3;
}

