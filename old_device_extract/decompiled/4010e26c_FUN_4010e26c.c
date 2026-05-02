// Function : FUN_4010e26c
// Address  : 0x4010e26c
// Size     : 196 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_4010e26c(ushort *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  while( true ) {
    if (param_2 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar1 = FUN_40109eec(*(undefined4 *)(param_2[3] + 4));
    uVar3 = *(ushort *)(param_2 + 2);
    uVar2 = FUN_40185288(*(undefined2 *)(param_2[3] + 0xc));
    if (0 < (int)(((uint)uVar3 - _DAT_3ffc6344) + iVar1 + (uint)((uVar2 & 3) != 0))) break;
    piVar5 = (int *)*param_2;
    uVar2 = FUN_40185360(param_2[1]);
    uVar3 = *param_1;
    uVar4 = (uint)uVar3;
    if (uVar2 <= uVar4) goto LAB_4010e2f0;
    pcVar7 = "lid pcb";
    uVar6 = 0x45c;
    while( true ) {
      uVar3 = (ushort)uVar4;
      uVar2 = (*(code *)&SUB_40094c54)("id cseg",uVar6,"segment",pcVar7);
LAB_4010e2f0:
      *param_1 = uVar3 - (short)uVar2;
      memw();
      uVar4 = (uint)*(ushort *)(param_2 + 2) + (uint)_DAT_3ffc6340;
      _DAT_3ffc6340 = (ushort)uVar4;
      memw();
      memw();
      FUN_4010ce44(param_2);
      param_2 = piVar5;
      if ((*param_1 == 0) || (piVar5 != (int *)0x0 || param_3 != 0)) break;
      pcVar7 = "ext->p)";
      uVar6 = 0x467;
      param_2 = (int *)0x0;
    }
  }
  return param_2;
}

