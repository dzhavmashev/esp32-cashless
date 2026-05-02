// Function : FUN_400d7f78
// Address  : 0x400d7f78
// Size     : 142 bytes


void FUN_400d7f78(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_400d6e3c(param_1,0x3ffc402c,500);
  if (iVar1 != 0) {
    FUN_400e7850(*(undefined4 *)(param_1 + 0x18));
  }
  iVar1 = FUN_400d6e3c(param_1,0x3ffc4020,5000);
  if (iVar1 != 0) {
    iVar1 = FUN_400da2bc(*(undefined4 *)(param_1 + 0xc));
    pcVar2 = "ATIONAL";
    if (iVar1 == 0) goto LAB_400d7ff5;
  }
  iVar1 = FUN_400d6e3c(param_1,0x3ffc4028,500);
  if (iVar1 != 0) {
    FUN_400d3d90(*(undefined4 *)(param_1 + 0x10));
  }
  iVar1 = FUN_400d6e3c(param_1,0x3ffc4024,10000);
  if (iVar1 != 0) {
    iVar1 = FUN_400f1a9c();
    FUN_400f06a4(0x3ffc5490,"NECTING",(uint)(iVar1 - *(int *)(param_1 + 0x34)) / 1000);
  }
  iVar1 = FUN_400f1a9c();
  if ((uint)(iVar1 - *(int *)(param_1 + 0x34)) < 0x493e1) {
    return;
  }
  pcVar2 = "econds\n";
LAB_400d7ff5:
  FUN_400f0780(0x3ffc5490,pcVar2);
  FUN_400d7d34(param_1,1);
  return;
}

