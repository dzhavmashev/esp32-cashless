// Function : FUN_40125b38
// Address  : 0x40125b38
// Size     : 362 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40125b38(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char cVar5;
  int in_a6;
  char in_a7;
  char *pcVar6;
  char cVar7;
  uint uVar8;
  undefined4 uVar9;
  char acStack_a4 [128];
  char *pcStack_24;
  
  memw();
  memw();
  pcStack_24 = _DAT_3ffc5708;
  pcVar2 = acStack_a4;
  if ((*(uint *)(param_1 + 4) & 2) != 0) {
    memw();
    iVar1 = FUN_40125968(param_1 + 4,pcVar2,0x80,0);
    if (iVar1 < 0) goto LAB_40125ba4;
    pcVar2 = pcVar2 + iVar1;
  }
  if ((*(uint *)(param_1 + 4) & 1) != 0) {
    *pcVar2 = -0x23;
    memw();
    uVar9 = *(undefined4 *)(param_1 + 0x10);
    pcVar2[2] = '\0';
    pcVar2[3] = 'P';
    pcVar2[4] = -0xe;
    pcVar2[5] = '\x01';
    pcVar2[7] = '\0';
    pcVar2[6] = '\x01';
    memw();
    memw();
    iVar1 = FUN_40106368(1,uVar9);
    pcVar3 = (char *)0xfffffff2;
    cVar5 = '\0';
    in_a6 = 0x50;
    in_a7 = '\x01';
    if (iVar1 != 0) goto LAB_40125bc2;
    goto LAB_40125ba2;
  }
  do {
    iVar4 = (int)pcVar2 - (int)acStack_a4;
    memw();
    (*(code *)&SUB_40094d80)(*(undefined4 *)(param_1 + 0x54));
    iVar1 = (*(code *)&SUB_40094d60)(iVar4);
    *(int *)(param_1 + 0x54) = iVar1;
    if (iVar1 == 0) goto LAB_40125ba2;
    memw();
    (*(code *)&SUB_4008b3d0)(iVar1,acStack_a4,iVar4);
    *(int *)(param_1 + 0x58) = iVar4;
    memw();
    iVar1 = 0;
LAB_40125ba4:
    do {
      while( true ) {
        param_1 = iVar1;
        pcVar3 = pcStack_24;
        pcVar2 = _DAT_3ffc5708;
        memw();
        memw();
        if (pcStack_24 == _DAT_3ffc5708) {
          return;
        }
        iVar1 = (*(code *)&SUB_40082ec4)();
        cVar5 = '\b';
LAB_40125bc2:
        pcVar2[8] = (char)((uint)iVar1 >> 0x18);
        pcVar2[9] = (char)((uint)iVar1 >> 0x10);
        pcVar2[10] = (char)((uint)iVar1 >> 8);
        memw();
        uVar9 = *(undefined4 *)(param_1 + 0xc);
        pcVar2[0xb] = (char)iVar1;
        memw();
        memw();
        iVar1 = FUN_401851dc(pcVar2 + 0xe,uVar9);
        if (iVar1 != 0) break;
LAB_40125ba2:
        iVar1 = -1;
      }
      pcVar6 = pcVar2 + 0xe + iVar1 * 4;
      pcVar2[0xc] = (char)iVar1;
      memw();
      uVar8 = *(uint *)(param_1 + 8);
      pcVar2[0xd] = (char)((uint)iVar1 >> 8);
      memw();
      cVar7 = (uVar8 & 1) != 0;
      if ((bool)cVar7) {
        pcVar6[4] = (char)pcVar3;
        pcVar3 = pcVar6 + 6;
        pcVar6[2] = cVar5;
        pcVar6[3] = (char)in_a6;
        pcVar6[5] = in_a7;
        memw();
        memw();
      }
      else {
        pcVar3 = pcVar6 + 2;
      }
      in_a6 = 2;
      if ((uVar8 & 2) == 0) {
        if (!(bool)cVar7) goto LAB_40125ba2;
      }
      else {
        *pcVar3 = '\0';
        cVar7 = cVar7 + '\x01';
        pcVar3[1] = 'P';
        in_a7 = -0xe;
        pcVar3[2] = -0xe;
        pcVar3[3] = '\x02';
        pcVar3 = pcVar3 + 4;
      }
      iVar1 = (int)pcVar3 - (int)pcVar2;
      pcVar6[1] = '\0';
      in_a6 = iVar1 + -2;
      *pcVar6 = cVar7;
      pcVar2[1] = (char)in_a6;
      memw();
      pcVar2 = pcVar3;
    } while (iVar1 < 0);
  } while( true );
}

