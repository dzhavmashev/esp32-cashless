// Function : FUN_400efb20
// Address  : 0x400efb20
// Size     : 638 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400efb20(int param_1,char *param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  char *pcStack_5c;
  int iStack_58;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar5 = param_1 + 0xa8;
  uVar4 = 0;
  uVar7 = 0;
  pcStack_5c = param_2;
  iStack_58 = param_3;
LAB_400efb41:
  for (uVar9 = 0; uVar9 < *(uint *)(param_1 + 0x90); uVar9 = uVar9 + 1) {
    iVar6 = *(int *)(param_1 + 0x8c) + uVar9 * 0x20;
    iVar1 = (*(code *)&LAB_40183a7b_1)(iVar6 + 0x10);
    if (iVar1 != 0) {
      if ((*(byte *)(iVar6 + 0x1f) & 0x80) == 0) {
        *(uint *)(iVar6 + 0x18) = uVar4;
        if (*(undefined1 **)(iVar6 + 0x10) != (undefined1 *)0x0) {
          **(undefined1 **)(iVar6 + 0x10) = (char)uVar4;
        }
      }
      else {
        *(byte *)(iVar6 + 0x1f) = *(byte *)(iVar6 + 0x1f) & 0x80;
        *(undefined1 *)(iVar6 + 0x10) = 0;
      }
    }
  }
  iVar1 = FUN_400ee814(param_1);
  if (iVar1 == 0) {
    iVar1 = -1;
    goto LAB_400efb92;
  }
  uVar9 = uVar4;
  if (iStack_58 != 0) {
    uVar9 = 1;
  }
  uVar8 = 1;
  if (param_4 == 0) {
    uVar8 = uVar4;
  }
  if ((uVar9 & uVar8) != 0) {
    FUN_400f0be8(auStack_34,"re");
    FUN_400f0e0c(auStack_44,param_4,10);
    FUN_400ede1c(param_1,auStack_34,auStack_44,uVar4,1);
    FUN_400f0a50(auStack_44);
    FUN_400f0a50(auStack_34);
  }
  FUN_400f0be8(auStack_44,&DAT_3f42161d);
  iVar1 = FUN_400eeb94(param_1,auStack_44);
  if (iVar1 != 0) {
    FUN_400f0be8(auStack_34,"ion");
    FUN_400ede1c(param_1,auStack_34,auStack_44,uVar4,1);
    FUN_400f0a50(auStack_34);
  }
  iVar1 = FUN_400ee0a4(param_1,pcStack_5c);
  if (iVar1 == 0) {
    uVar10 = 0xfffffffe;
  }
  else {
    if ((uVar9 & uVar8) == 0) goto LAB_400efcea;
    for (uVar9 = 0; uVar9 < param_4; uVar9 = uVar9 + iVar1) {
      iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))
                        (*(int **)(param_1 + 8),iStack_58 + uVar9,param_4 - uVar9);
      if (iVar1 == 0) {
        FUN_400f1ab4(100);
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0xc))
                          (*(int **)(param_1 + 8),iStack_58 + uVar9,param_4 - uVar9);
        if (iVar1 == 0) {
          uVar11 = func_0x40085c04();
          uVar10 = (*(code *)&SUB_4000cff8)((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),1000,0);
          uVar2 = FUN_401847ec(&DAT_3f409fe7);
          FUN_4012105c("ity",uVar10,uVar2,0x276,"connect");
          break;
        }
      }
    }
    if (param_4 == uVar9) goto LAB_400efcea;
    uVar10 = 0xfffffffd;
  }
  param_1 = FUN_400ee484(param_1,uVar10);
  FUN_400f0a50(auStack_44);
  do {
    uVar4 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
LAB_400efcea:
    iVar1 = FUN_400ef644(param_1);
    iVar6 = *(int *)(param_1 + 0xa0);
    uVar9 = uVar4;
    if (((iVar6 != 0) && (uVar7 < *(ushort *)(param_1 + 0xa4))) &&
       (iVar3 = (*(code *)&LAB_40183a7b_1)(iVar5), iVar3 != 0)) {
      if (iVar1 < 0x130) {
        if (0x12d < iVar1) {
          uVar7 = uVar7 + 1;
          uVar9 = FUN_400ee6c4(param_1,iVar5);
          if (uVar9 != 0) {
            iStack_58 = 0;
            pcStack_5c = "dentity";
            param_4 = uVar4;
          }
          goto LAB_400efd64;
        }
        iVar3 = 0x12d;
      }
      else {
        iVar3 = 0x133;
      }
      if ((iVar1 == iVar3) &&
         (((iVar6 == 2 || (iVar6 = func_0x4008bdf4(pcStack_5c,"dentity"), iVar6 == 0)) ||
          (iVar6 = func_0x4008bdf4(pcStack_5c,"hunk!\r\n"), iVar6 == 0)))) {
        uVar7 = uVar7 + 1;
        uVar9 = FUN_400ee6c4(param_1,iVar5);
      }
    }
LAB_400efd64:
    FUN_400f0a50(auStack_44);
    if (uVar9 != 0) goto LAB_400efb41;
LAB_400efb92:
    param_1 = FUN_400ee484(param_1,iVar1);
  } while( true );
}

