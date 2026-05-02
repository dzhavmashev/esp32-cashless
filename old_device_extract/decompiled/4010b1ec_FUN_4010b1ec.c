// Function : FUN_4010b1ec
// Address  : 0x4010b1ec
// Size     : 132 bytes


undefined1 FUN_4010b1ec(int param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int aiStack_38 [5];
  undefined1 uStack_24;
  
  piVar2 = param_3;
  if (param_2 == (int *)0x0) {
    piVar2 = (int *)(*(code *)&SUB_40094c54)("d netif",0x1d5,"reports","d netif");
  }
  iVar4 = *(int *)(param_1 + 4);
  uVar3 = 0;
  aiStack_38[0] = *param_2;
  if (aiStack_38[0] != iVar4) {
    *(undefined1 *)(param_3 + 5) = *(undefined1 *)(param_1 + 0x18);
    memw();
    cVar1 = *(char *)(param_1 + 0x18);
    uStack_24 = 0;
    memw();
    *param_3 = iVar4;
    if (cVar1 == '\x06') {
      param_3[1] = *(int *)(param_1 + 8);
      param_3[2] = *(int *)(param_1 + 0xc);
      param_3[3] = *(int *)(param_1 + 0x10);
      uVar3 = *(undefined1 *)(param_1 + 0x14);
    }
    else {
      param_3[3] = 0;
      param_3[2] = 0;
      param_3[1] = 0;
      memw();
    }
    *(undefined1 *)(piVar2 + 4) = uVar3;
    memw();
    memw();
    FUN_4010b08c(piVar2,aiStack_38);
    *(int *)(param_1 + 4) = *param_2;
    *(undefined1 *)(param_1 + 0x18) = 0;
    memw();
    memw();
    FUN_4010b1a0(param_1,1);
    uVar3 = 1;
  }
  return uVar3;
}

