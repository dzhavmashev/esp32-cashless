// Function : FUN_400e1000
// Address  : 0x400e1000
// Size     : 38 bytes


undefined4 FUN_400e1000(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_2 == 0) {
      *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) & 0x80;
      uVar1 = 1;
    }
    else {
      uVar1 = FUN_400d43ec(param_1,param_2,param_3);
    }
  }
  return uVar1;
}

