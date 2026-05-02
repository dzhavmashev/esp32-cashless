// Function : FUN_4012cd4c
// Address  : 0x4012cd4c
// Size     : 65 bytes


int FUN_4012cd4c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_4012cb68(param_1);
  if (iVar1 == 0) {
    if ((*(char *)(*param_1 + 5) == '\x01') && (param_1[2] == 3)) {
      if (*(char *)(*param_1 + 4) == '\x01') {
        *(undefined4 *)(param_1[0x11] + 0x238) = 1;
      }
      else {
        *(undefined4 *)(param_1[0x11] + 0x23c) = 1;
        memw();
      }
    }
    param_1[1] = 0;
    param_1[2] = 1;
    memw();
    iVar1 = FUN_4012c9dc(param_1);
  }
  return iVar1;
}

