// Function : FUN_400d7e60
// Address  : 0x400d7e60
// Size     : 276 bytes


void FUN_400d7e60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400d6e3c(param_1,0x3ffc4030,300);
  if (iVar1 != 0) {
    FUN_400e7850(*(undefined4 *)(param_1 + 0x18));
  }
  FUN_400e6618(0x3ffc4d58);
  iVar1 = (*(code *)&LAB_4018425a_2)(0x3ffc4d58);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x40) + 1;
    *(int *)(param_1 + 0x40) = iVar1;
    FUN_400f06a4(0x3ffc5490," -> %s\n",iVar1,*(undefined4 *)(param_1 + 0x44));
    if ((*(uint *)(param_1 + 0x40) == (*(uint *)(param_1 + 0x40) / 0x1e) * 0x1e) &&
       (iVar1 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8)), iVar1 == 1)) {
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
      FUN_400f06a4(0x3ffc5490,"s: %d)\n");
      FUN_400e65d0(0x3ffc4d58,10000);
      if (3 < *(uint *)(param_1 + 0x44)) {
        FUN_400f0780(0x3ffc5490,"#%d/4)\n");
        FUN_400f0780(0x3ffc5490,"failed)");
        FUN_400f1ab4(1000);
        FUN_400efe2c(0x3ffc53f4);
      }
    }
    else {
      iVar1 = FUN_400da170(*(undefined4 *)(param_1 + 0xc));
      if (iVar1 == 0) {
        if (*(uint *)(param_1 + 0x40) == (*(uint *)(param_1 + 0x40) / 10) * 10) {
          iVar1 = FUN_400f1a9c();
          FUN_400f06a4(0x3ffc5490,"resh...",*(undefined4 *)(param_1 + 0x40),
                       (uint)(iVar1 - *(int *)(param_1 + 0x30)) / 1000);
        }
      }
      else {
        FUN_400f0780(0x3ffc5490,"econds\n");
        iVar1 = FUN_40183e94(*(undefined4 *)(param_1 + 8));
        if (iVar1 == 0) {
          FUN_400f0780(0x3ffc5490,"sfully!");
          uVar2 = 2;
        }
        else {
          FUN_400f0780(0x3ffc5490,"G state");
          uVar2 = 4;
        }
        FUN_400d7d34(param_1,uVar2);
      }
    }
  }
  return;
}

