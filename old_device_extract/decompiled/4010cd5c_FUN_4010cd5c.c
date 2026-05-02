// Function : FUN_4010cd5c
// Address  : 0x4010cd5c
// Size     : 123 bytes


int FUN_4010cd5c(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int in_t0;
  
  iVar3 = param_1;
  if (param_1 != 0) goto LAB_4010cd75;
  pcVar7 = "ng != 0";
  uVar5 = 0x3a7;
  iVar3 = in_t0;
  while( true ) {
    (*(code *)&SUB_40094c54)(" LISTEN",uVar5,"_recved",pcVar7);
    in_t0 = iVar3;
LAB_4010cd75:
    iVar4 = *(int *)(param_1 + 0x58);
    uVar1 = *(ushort *)(iVar3 + 0x5e);
    iVar6 = *(int *)(param_1 + 0x50);
    iVar2 = ((uint)*(ushort *)(param_1 + 0x54) - iVar4) + iVar6;
    if (-1 < (int)(iVar2 - (uint)(ushort)((uVar1 < 0xb40) * uVar1 + (ushort)(uVar1 >= 0xb40) * 0xb40
                                         ))) {
      *(ushort *)(iVar3 + 0x56) = *(ushort *)(param_1 + 0x54);
      memw();
      goto LAB_4010cd9b;
    }
    if (0 < iVar6 - iVar4) {
      *(undefined2 *)(iVar3 + 0x56) = 0;
      memw();
      goto LAB_4010cdae;
    }
    param_1 = 0xffff;
    if ((uint)(iVar4 - iVar6) < 0x10000) break;
    pcVar7 = "lid pcb";
    uVar5 = 0x3b7;
    iVar3 = in_t0;
  }
  *(short *)(iVar3 + 0x56) = (short)(iVar4 - iVar6);
  memw();
  memw();
LAB_4010cdae:
  iVar2 = 0;
  memw();
LAB_4010cd9b:
  memw();
  return iVar2;
}

