// Function : FUN_4011d908
// Address  : 0x4011d908
// Size     : 98 bytes


void FUN_4011d908(int *param_1)

{
  undefined1 uVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 1) = 0xf5;
  memw();
  if (((uint *)*param_1)[2] != 0) {
    uVar2 = *(uint *)*param_1;
    if ((uVar2 & 0xf0) == 0x20) {
      if ((uVar2 & 8) == 0) {
        if (param_1[5] == 0) {
          uVar1 = FUN_401164fc();
        }
        else {
          uVar1 = FUN_401165d8(param_1[3],param_1[2]);
        }
      }
      else if (param_1[5] == 0) {
        memw();
        uVar1 = FUN_4011878c();
      }
      else {
        uVar1 = FUN_401188a8();
      }
      *(undefined1 *)(param_1 + 1) = uVar1;
      memw();
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0xfa;
      memw();
      memw();
    }
  }
  memw();
  FUN_4011ad9c(param_1[9]);
  return;
}

