// Function : FUN_40132d3c
// Address  : 0x40132d3c
// Size     : 25 bytes


undefined4 FUN_40132d3c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffff9f00;
  if (*param_1 != 0) {
    uVar1 = 0;
    param_1[9] = 0;
  }
  memw();
  return uVar1;
}

