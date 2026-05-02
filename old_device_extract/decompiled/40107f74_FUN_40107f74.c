// Function : FUN_40107f74
// Address  : 0x40107f74
// Size     : 169 bytes


int FUN_40107f74(uint *param_1,ushort param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  ushort uVar5;
  ushort uVar6;
  undefined4 in_t0;
  
  piVar3 = (int *)&DAT_3ffc58c8;
  iVar2 = 0;
  while( true ) {
    FUN_4011b020();
    uVar6 = (ushort)in_t0;
    if ((*piVar3 == 0) && (*(char *)((int)piVar3 + 0xf) == '\0')) break;
    iVar2 = iVar2 + 1;
    FUN_4011b040();
    piVar3 = piVar3 + 6;
    if (iVar2 == 0x10) {
LAB_4010801b:
      iVar2 = -1;
LAB_40108007:
      memw();
      return iVar2;
    }
  }
  iVar4 = iVar2 * 0x18;
  *(undefined1 *)(iVar4 + 0x3ffc58d8) = 0;
  (&DAT_3ffc58d7)[iVar4] = 1;
  memw();
  *(uint **)(&DAT_3ffc58c8 + iVar4) = param_1;
  memw();
  FUN_4011b040();
  *(undefined4 *)(iVar4 + 0x3ffc58cc) = 0;
  uVar5 = (ushort)*(byte *)(iVar4 + 0x3ffc58d6);
  if (*(byte *)(iVar4 + 0x3ffc58d6) != 0) {
    memw();
    uVar5 = uVar6;
    (*(code *)&SUB_40094c54)("!= NULL",0x239,"_locked","!= NULL");
  }
  uVar6 = 1;
  if ((*param_1 & 0xf0) == 0x10) {
    uVar6 = uVar5;
  }
  *(ushort *)(iVar4 + 0x3ffc58d2) = uVar6 | param_2 & 1;
  memw();
  *(ushort *)(iVar4 + 0x3ffc58d0) = uVar5;
  *(ushort *)(iVar4 + 0x3ffc58d4) = uVar5;
  memw();
  if ((*(int *)(iVar4 + 0x3ffc58dc) != 0) ||
     (cVar1 = FUN_4011acbc(iVar4 + 0x3ffc58dc), cVar1 == '\0')) {
    iVar2 = iVar2 + 0x30;
    goto LAB_40108007;
  }
  goto LAB_4010801b;
}

