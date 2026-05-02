// Function : FUN_4015a84c
// Address  : 0x4015a84c
// Size     : 95 bytes


undefined4
FUN_4015a84c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,uint param_9)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = 4;
  uVar3 = uVar1;
  if (((((param_9 & 0x20) == 0) && ((param_9 & 0x10) != 0)) && (uVar3 = param_3 - 1, 1 < uVar3)) &&
     (uVar3 = uVar1, param_3 == 0)) {
    uVar3 = 1;
  }
  if ((param_9 & 0x10) == 0) {
    if ((param_9 & 0x20) != 0) {
      if ((param_9 & 1) == 0) {
        if ((param_9 & 0xc) == 4) {
          param_4 = 0;
        }
      }
      else {
        param_4 = 2;
      }
    }
  }
  else {
    param_4 = 1;
  }
  memw();
  uVar2 = FUN_4015a720(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar3);
  return uVar2;
}

