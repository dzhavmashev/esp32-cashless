// Function : FUN_4018e2e4
// Address  : 0x4018e2e4
// Size     : 108 bytes


void FUN_4018e2e4(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  (*(code *)&SUB_4008b530)(param_2,0,0x1c);
  if (param_1 != 0) {
    (*(code *)&SUB_40094838)(param_1);
    uVar1 = (*(code *)&SUB_400940f8)(*(undefined4 *)(param_1 + 0x10));
    FUN_4018df80(uVar1,0x4018e348,param_2);
    iVar6 = param_2[4];
    iVar2 = (*(code *)&SUB_40093dcc)();
    iVar4 = *(int *)(param_1 + 0xc);
    iVar3 = (*(code *)&SUB_400947a8)(*(undefined4 *)(param_1 + 0x10));
    iVar7 = *(int *)(param_1 + 4);
    iVar5 = *(int *)(param_1 + 8);
    param_2[1] = ((iVar4 - iVar7) - iVar3) - iVar6 * iVar2;
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    param_2[3] = iVar5;
    *param_2 = iVar7;
    memw();
    iVar2 = FUN_4018dfb8(uVar1,param_2[2]);
    param_2[2] = iVar2;
    memw();
    (*(code *)&SUB_40094848)(param_1);
  }
  return;
}

