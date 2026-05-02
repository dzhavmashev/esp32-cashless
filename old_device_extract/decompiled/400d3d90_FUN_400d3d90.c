// Function : FUN_400d3d90
// Address  : 0x400d3d90
// Size     : 136 bytes


void FUN_400d3d90(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_400da2bc(*(undefined4 *)(param_1 + 0x1c));
  if (((iVar1 != 0) && (*(char *)(param_1 + 0x18) == '\0')) && (*(char *)(param_1 + 0x19) == '\0'))
  {
    iVar1 = FUN_400d3648(param_1);
    if (iVar1 == 0) {
      FUN_400f0780(0x3ffc5490,"%d: %s\n");
      *(undefined1 *)(param_1 + 0x19) = 1;
      FUN_400d36e0(param_1,4);
      iVar2 = *(int *)(param_1 + 0x58);
      iVar1 = 1;
    }
    else {
      FUN_400f0780(0x3ffc5490,"tivated");
      *(undefined1 *)(param_1 + 0x18) = 1;
      iVar1 = FUN_400d3a50(param_1);
      if (iVar1 == 0) {
        FUN_400f0780(0x3ffc5490,"essful!");
        uVar3 = 5;
      }
      else {
        FUN_400f0780(0x3ffc5490,"tion...");
        uVar3 = 4;
      }
      FUN_400d36e0(param_1,uVar3);
      *(undefined2 *)(param_1 + 0x18) = 0x100;
      iVar2 = *(int *)(param_1 + 0x58);
    }
    if (iVar2 != 0) {
      FUN_400d3a14(param_1 + 0x50,iVar1);
    }
  }
  return;
}

