// Function : FUN_401694ec
// Address  : 0x401694ec
// Size     : 448 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401694ec(uint *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  ushort local_90 [14];
  ushort local_74 [18];
  ushort *puStack_50;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  int iStack_40;
  char *pcStack_3c;
  ushort *puStack_38;
  uint *puStack_34;
  uint uStack_30;
  
  puStack_38 = local_90;
  local_74[0] = (ushort)(*param_1 >> 0x10);
  local_90[0] = (ushort)*param_1 & 0x1ff;
  memw();
  pcStack_3c = (char *)(param_2 + -1);
  uStack_30 = 1;
  iStack_40 = 0;
  puStack_34 = param_1;
  do {
    if (pcStack_3c[1] == '\0') {
      uVar2 = uStack_30 - 2;
      iVar5 = (int)(char)uVar2;
      if (iVar5 != -1) {
        cVar1 = *pcStack_3c;
        while (cVar1 != '\x01') {
          uVar2 = (uVar2 & 0xff) - 1;
          iVar5 = (int)(char)uVar2;
          if (iVar5 == -1) break;
          cVar1 = *(char *)(param_2 + iVar5);
        }
      }
      if (uStack_30 == 0xe) {
LAB_40169680:
        puStack_50 = local_74 + iStack_40;
        uVar4 = *puStack_38;
        uVar3 = (uint)uVar4;
        uVar6 = local_74[iStack_40];
        uVar2 = (uint)uVar6;
        if (iVar5 != -1) {
LAB_40169588:
          iVar7 = iVar5;
          goto LAB_40169591;
        }
        iStack_4c = 0;
        iVar5 = iStack_4c;
        uStack_48 = uVar2;
        uStack_44 = uVar3;
      }
      else {
        iVar7 = (int)(char)uStack_30;
        cVar1 = pcStack_3c[2];
        uVar2 = uStack_30;
        while (cVar1 != '\x01') {
          uVar3 = uVar2 + 1;
          uVar2 = uVar3 & 0xff;
          iVar7 = (int)(char)uVar3;
          if (uVar2 == 0xe) goto LAB_40169680;
          cVar1 = *(char *)(param_2 + iVar7);
        }
        puStack_50 = local_74 + iStack_40;
        uVar2 = (uint)local_74[iStack_40];
        uVar3 = (uint)*puStack_38;
        if ((iVar5 != -1) && (iStack_40 - iVar5 < iVar7 - iStack_40)) goto LAB_40169588;
LAB_40169591:
        uVar6 = local_74[iVar7];
        uVar4 = local_90[iVar7];
        iStack_4c = uVar3 - uVar4;
        iVar5 = uVar2 - uVar6;
        uStack_48 = (uint)uVar6;
        uStack_44 = (uint)uVar4;
      }
      iVar5 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iVar5);
      if (5 < iVar5) {
        *puStack_50 = uVar6;
        memw();
        uVar2 = uStack_48;
      }
      iVar5 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_4c);
      if (5 < iVar5) {
        *puStack_38 = uVar4;
        uVar3 = uStack_44;
      }
      *puStack_34 = uVar2 << 0x10 | uVar3;
    }
    uStack_30 = uStack_30 + 1 & 0xff;
    iStack_40 = iStack_40 + 1;
    puStack_34 = puStack_34 + 1;
    puStack_38 = puStack_38 + 1;
    pcStack_3c = pcStack_3c + 1;
    if (uStack_30 == 0xf) {
      return;
    }
  } while( true );
}

