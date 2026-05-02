// Function : FUN_401063f0
// Address  : 0x401063f0
// Size     : 96 bytes


void FUN_401063f0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  (*(code *)&SUB_40085bfc)();
  uVar3 = (*(code *)&SUB_4000c988)();
  (*(code *)&SUB_40002954)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x412e8480);
  iVar1 = (*(code *)&SUB_40002ac4)();
  (*(code *)&SUB_40085a10)(param_1[3]);
  if (*param_1 != 0) {
    iVar1 = *(int *)(*param_1 + 0x58) - iVar1;
    uVar3 = (*(code *)&SUB_4000c944)((uint)(-1 < iVar1) * iVar1 + 1);
    (*(code *)&SUB_4006358c)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x412e8480);
    uVar3 = FUN_40170920();
    uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    (*(code *)&SUB_40085910)(param_1[3],uVar2,(int)uVar3,uVar2);
  }
  return;
}

