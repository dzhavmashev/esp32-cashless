// Function : FUN_401691b0
// Address  : 0x401691b0
// Size     : 825 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401691b0(uint param_1,short param_2,undefined2 *param_3,uint param_4)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  ushort auStack_70 [5];
  undefined2 uStack_66;
  undefined2 uStack_64;
  char local_5f;
  undefined1 auStack_5e [14];
  uint uStack_50;
  uint uStack_4c;
  char *pcStack_48;
  uint uStack_44;
  undefined2 *puStack_40;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  int iStack_30;
  
  (*(code *)&SUB_4008b3d0)(auStack_5e,0x3ffc32c8,5);
  (*(code *)&SUB_4008b3d0)(auStack_70,0x3ffc32d0,10);
  uStack_34 = param_1 & 0xff;
  iStack_3c = (int)param_2;
  uStack_44 = param_4 & 0xff;
  (**(code **)(_DAT_3ffc7e64 + 0x28))(1);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(100,0,4,7,7,1);
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc | 0x8000000;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)();
  _DAT_3ff450dc = _DAT_3ff450dc & 0xefffffff;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc & 0xffffefff;
  uVar9 = _DAT_3ffca514 >> 6 & 0x1f;
  uVar10 = (uint)(char)uVar9;
  memw();
  if (0xf < uVar10) {
    uVar10 = uVar9 - 0x20;
  }
  uVar9 = (uint)(char)(_DAT_3ffca514 & 0x3f);
  if (0x1f < uVar9) {
    uVar9 = (_DAT_3ffca514 & 0x3f) - 0x40;
  }
  pcStack_48 = &local_5f;
  (**(code **)(_DAT_3ffc7e64 + 0x128))(uVar10,1);
  (**(code **)(_DAT_3ffc7e64 + 0x128))(uVar9,0);
  uStack_50 = 0;
  puStack_40 = param_3;
  uStack_66 = 0x100;
  uStack_64 = 0x100;
  memw();
  do {
    uStack_4c = auStack_70[uStack_50] + 0x80 & 0xffff;
    cVar8 = pcStack_48[1];
    (**(code **)(_DAT_3ffc7e64 + 0x20))(cVar8,0x104,uStack_4c);
    if (uStack_34 != 0) {
      pcVar4 = *(code **)(_DAT_3ffc7e64 + 0xb8);
      uVar2 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
      (*pcVar4)(1,1,uVar2 | 2);
    }
    (**(code **)(_DAT_3ffc7e64 + 0x150))(4000,&uStack_66,10,0);
    bVar7 = 0;
    uVar9 = 0x18;
    uStack_38 = (uint)((uStack_50 & 0xff) != 0);
    do {
      uVar10 = uVar9 & 0xff;
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,1,0x1f1);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,1,0x1f9);
      (**(code **)(_DAT_3ffc7e64 + 0x44))(1,iStack_3c,uVar10,0,0);
      (**(code **)(_DAT_3ffc7e64 + 0x144))(1,0x3ff);
      iVar5 = (*(code *)&SUB_40084594)(0x3ff460e4);
      iVar5 = iVar5 >> 7;
      if (uStack_44 != 0) {
        iStack_30 = (*(code *)&SUB_40084594)(0x3ff460dc);
        iVar6 = (*(code *)&SUB_40084594)(0x3ff460e0);
        FUN_40168620(0x3ffc3384,iVar5,0x1000,0x20000,cVar8,uVar9,iStack_30 >> 0x10,iVar6 >> 0x10);
      }
      (**(code **)(_DAT_3ffc7e64 + 0x148))();
      (**(code **)(_DAT_3ffc7e64 + 0x4c))(1);
      sVar1 = (short)uVar9;
      if (iVar5 < 0x20001) {
        if (0xfff < iVar5) break;
        if (((bVar7 & 1) == 0) && (uStack_38 != 0)) {
          uVar9 = (uint)(short)((ushort)((int)uVar9 < 0x78) * sVar1 +
                               (ushort)((int)uVar9 >= 0x78) * 0x78);
          cVar8 = *pcStack_48;
        }
        else {
          uVar9 = 0;
        }
LAB_401694da:
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,cVar8);
      }
      else {
        if (((bVar7 & 1) == 0) && (cVar8 != '\0')) {
          uVar9 = (uint)(short)((ushort)((int)uVar9 < 0x78) * sVar1 +
                               (ushort)((int)uVar9 >= 0x78) * 0x78);
          cVar8 = pcStack_48[2];
          goto LAB_401694da;
        }
        iVar5 = (int)(short)(sVar1 + 0x18);
        (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,cVar8);
        uVar9 = 0;
        if (-1 < iVar5) {
          uVar9 = (uint)(iVar5 < 0x78) * iVar5 + (uint)(iVar5 >= 0x78) * 0x78;
        }
      }
      bVar7 = bVar7 + 1;
      uVar10 = uVar9;
    } while (bVar7 != 2);
    if (uStack_44 != 0) {
      FUN_40168620(0x3ffc33cc,cVar8,0x104,uVar9,uStack_4c,uStack_50,2);
    }
    uVar9 = uStack_50 + 1;
    pcStack_48 = pcStack_48 + 1;
    uStack_50 = uVar9;
    uVar3 = (**(code **)(_DAT_3ffc7e64 + 0x164))(iStack_3c,uVar10,uStack_44);
    *puStack_40 = uVar3;
    puStack_40 = puStack_40 + 1;
    if (uVar9 == 4) {
      (**(code **)(_DAT_3ffc7e64 + 0x28))(0);
      (**(code **)(_DAT_3ffc7e64 + 0xa8))(100,0,uStack_50,7);
      _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
      _DAT_3ff450dc = _DAT_3ff450dc | 0x10000000;
      memw();
      uVar9 = (*(code *)&SUB_40084594)();
      memw();
      _DAT_3ff450dc = uVar9 | 0x1000;
      return;
    }
  } while( true );
}

