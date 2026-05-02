// Function : FUN_40165750
// Address  : 0x40165750
// Size     : 606 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40165750(uint *param_1,byte param_2,int param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  int iStack_3c;
  uint uStack_38;
  uint uStack_34;
  
  if (param_3 != 0x40) {
    uVar8 = _DAT_3ffc06fc[1];
    if (param_3 == 0x62) {
      uVar5 = 0;
      iStack_3c = 0;
      uVar11 = 8;
      uStack_34 = 0x1c;
      uStack_38 = 3;
    }
    else {
      memw();
      uVar11 = FUN_4018b754(uVar8);
      uVar5 = uVar11 & 0xffff;
      iStack_3c = 0;
      if (uVar5 != 0) {
        puVar9 = (undefined1 *)(uVar8 + (uVar11 & 0xffff) + 0x18);
        memw();
        iStack_3c = FUN_40165300(uVar8 + 0x18,puVar9);
        if (iStack_3c == 1) {
          uVar1 = *(undefined1 *)(uVar8 + 0x19);
          *puVar9 = *(undefined1 *)(uVar8 + 0x18);
          memw();
          uVar2 = *(undefined1 *)(uVar8 + 0x1a);
          puVar9[1] = uVar1;
          memw();
          uVar1 = *(undefined1 *)(uVar8 + 0x1b);
          puVar9[2] = uVar2;
          puVar9[3] = uVar1;
          memw();
          memw();
        }
        else if (iStack_3c == 2) {
          uVar5 = 0;
        }
      }
      uVar3 = *(ushort *)(uVar8 + uVar5 + 0x1c);
      uVar11 = 0;
      for (puVar6 = _DAT_3ffc06fc; puVar6 != param_1; puVar6 = (uint *)puVar6[2]) {
        memw();
        uVar11 = (*puVar6 >> 0xc & 0xfff) + uVar11 & 0xffff;
      }
      memw();
      uVar10 = uVar3 & 0xf;
      uStack_34 = uVar11 + ((*param_1 >> 0xc & 0xfff) - uVar5) & 0xffff;
      uVar11 = 1;
      uStack_38 = uVar10;
      if ((uVar3 & 0xf) != 0) {
        uStack_38 = 1;
        if (uVar10 != 4) {
          uStack_38 = 2;
        }
        uVar11 = 0x14;
        if (uVar10 == 4) {
          uVar11 = 2;
        }
        memw();
      }
    }
    if ((uVar11 & _DAT_3ffc0730) != 0) {
      memw();
      puVar6 = (uint *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(8);
      if (puVar6 != (uint *)0x0) {
        memw();
        uVar11 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(uStack_34);
        if (uVar11 != 0) {
          if (param_3 == 0x62) {
            puVar9 = (undefined1 *)(uVar8 + uVar5 + 0x18);
            (*(code *)&SUB_4008b3d0)(uVar11,uVar8,0x18);
            uVar1 = puVar9[1];
            *(undefined1 *)(uVar11 + 0x18) = *puVar9;
            memw();
            uVar2 = puVar9[2];
            *(undefined1 *)(uVar11 + 0x19) = uVar1;
            memw();
            uVar1 = puVar9[3];
            *(undefined1 *)(uVar11 + 0x1a) = uVar2;
            *(undefined1 *)(uVar11 + 0x1b) = uVar1;
            memw();
            memw();
          }
          else {
            if (param_2 < 2) {
              (*(code *)&SUB_4008b3d0)(uVar11,uVar8,0x18);
              memw();
              (*(code *)&SUB_4008b3d0)
                        (uVar11 + 0x18,uVar8 + uVar5 + 0x18,
                         ((*_DAT_3ffc06fc >> 0xc & 0xfff) - 0x18) - uVar5);
            }
            else {
              bVar4 = true;
              memw();
              uVar8 = uVar11;
              for (puVar12 = _DAT_3ffc06fc; puVar12 != param_1; puVar12 = (uint *)puVar12[2]) {
                if (bVar4) {
                  (*(code *)&SUB_4008b3d0)(uVar8,puVar12[1],0x18);
                  memw();
                  uVar8 = uVar8 + 0x18;
                  (*(code *)&SUB_4008b3d0)
                            (uVar8,puVar12[1] + uVar5 + 0x18,
                             ((*puVar12 >> 0xc & 0xfff) - 0x18) - uVar5);
                  memw();
                  uVar10 = ((*puVar12 >> 0xc & 0xfff) - 0x18) - uVar5;
                }
                else {
                  memw();
                  (*(code *)&SUB_4008b3d0)(uVar8,puVar12[1],*puVar12 >> 0xc & 0xfff);
                  memw();
                  uVar10 = *puVar12 >> 0xc & 0xfff;
                }
                uVar8 = uVar8 + uVar10;
                bVar4 = false;
              }
              memw();
              (*(code *)&SUB_4008b3d0)(uVar8,puVar12[1],*puVar12 >> 0xc & 0xfff);
              memw();
            }
            if (uVar5 != 0) {
              FUN_40165378(_DAT_3ffc06fc[1] + 0x18,uVar5,uVar11,uVar11 + 0x1c,
                           uStack_34 - 0x1c & 0xffff,iStack_3c);
            }
          }
          puVar6[1] = uVar11;
          *puVar6 = uStack_38;
          memw();
          iVar7 = (*(code *)&SUB_40087bcc)(0xd,puVar6);
          if (iVar7 != 1) {
            return;
          }
          (**(code **)(_DAT_3ffc1a34 + 0xb0))(uVar11);
        }
        (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar6);
      }
    }
  }
  return;
}

