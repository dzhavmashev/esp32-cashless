// Function : FUN_400e8cc4
// Address  : 0x400e8cc4
// Size     : 796 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e8cc4(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  int aiStack_188 [45];
  int iStack_d4;
  undefined1 auStack_d0 [4];
  code *pcStack_cc;
  undefined1 auStack_c8 [8];
  int iStack_c0;
  code *pcStack_bc;
  code *pcStack_b8;
  int iStack_b4;
  undefined1 auStack_b0 [140];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_1 == (int *)0x0) goto LAB_400e8fb9;
  iVar5 = *param_1;
  if (iVar5 == 1) {
    FUN_400e97d8();
  }
  else if (iVar5 == 2) {
    FUN_400e9078(6);
    FUN_400e815c(8);
    iVar5 = FUN_40146f58(_DAT_3ffbdb84);
    if (iVar5 != 0) {
      uVar6 = func_0x40085c04();
      uVar1 = FUN_401847ec("02X%02X");
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
      FUN_4012105c("x%04x\r\n",uVar2,uVar1,0x417,"op");
    }
  }
  else {
    if (iVar5 == 3) {
      FUN_400e9078(0xff);
      uVar1 = 0x78;
      goto LAB_400e8db8;
    }
    if (iVar5 == 4) {
      FUN_400e9078(0);
      uVar1 = 0x10;
    }
    else {
      if (iVar5 == 5) {
        bVar3 = *(byte *)((int)param_1 + 0x2b);
        if (bVar3 == 0) {
          bVar3 = 1;
LAB_400e8dfe:
          uVar1 = 5;
          if ((bVar3 & 0xfb) == 200) goto LAB_400e8e11;
          if (bVar3 != 2) {
            uVar1 = 6;
            goto LAB_400e8e11;
          }
        }
        else {
          uVar1 = 1;
          if ((bVar3 != 0xc9) && ((bVar3 != 0xca || (uVar1 = 4, DAT_3ffbdb80 != '\0'))))
          goto LAB_400e8dfe;
LAB_400e8e11:
          FUN_400e9078(uVar1);
        }
        FUN_400e8174(0x70);
        if (bVar3 != 8) {
          if (DAT_3ffbdb80 == '\0') {
            iVar5 = FUN_400e9684(&DAT_3ffc516c);
            if ((iVar5 == 0) || (iVar5 = FUN_40184288(bVar3), iVar5 == 0)) {
              if (bVar3 == 0xcb) {
                FUN_400e9078(4);
              }
              goto LAB_400e8ce4;
            }
          }
          else {
            DAT_3ffbdb80 = '\0';
          }
          FUN_400e9570(&DAT_3ffc516c,0);
          FUN_400e93ec(&DAT_3ffc516c);
        }
        goto LAB_400e8ce4;
      }
      if (iVar5 == 7) {
        FUN_400e9078(3);
        uVar1 = 0x30;
      }
      else {
        if (iVar5 == 9) {
          FUN_400e9078(0);
          uVar1 = 0x20;
LAB_400e8db8:
          FUN_400e8174(uVar1);
          goto LAB_400e8ce4;
        }
        uVar1 = 1;
        if (iVar5 != 10) {
          uVar1 = 5;
          if (iVar5 == 0xb) goto LAB_400e8db8;
          uVar1 = 4;
          if (iVar5 != 0xc) {
            if (iVar5 == 0xd) {
              iVar5 = FUN_40146f00(aiStack_188);
              if ((iVar5 == 0) && (iStack_d4 != 0)) goto LAB_400e8ce4;
              uVar1 = 4;
              goto LAB_400e8db8;
            }
            uVar1 = 0x80;
            if (iVar5 != 0x12) {
              uVar1 = 0x780;
              if (iVar5 == 0x13) goto LAB_400e8db8;
              uVar1 = 0x100;
              if (iVar5 != 0x14) {
                if (iVar5 == 0x15) {
                  uVar1 = 0x700;
                  goto LAB_400e8db8;
                }
                uVar1 = 0x300;
                if (((iVar5 != 0x16) && (uVar1 = 0x50, iVar5 != 8)) && (uVar1 = 2, iVar5 != 0x10)) {
                  if (iVar5 != 0x17) {
                    if (iVar5 == 0x1f) {
                      iVar5 = 0;
                      if ((char)param_1[0x19] != '\0') {
                        iVar5 = (int)param_1 + 0x65;
                      }
                      FUN_400e90f4(&DAT_3ffc516c,param_1 + 1,param_1 + 9,0,iVar5,1);
                    }
                    else if (iVar5 == 0x20) {
                      FUN_40106928(2);
                      DAT_3ffc51b8 = 1;
                    }
                    goto LAB_400e8ce4;
                  }
                  uVar1 = 0x500;
                }
              }
            }
          }
        }
      }
    }
    FUN_400e815c(uVar1);
  }
LAB_400e8ce4:
  for (uVar4 = 0; uVar4 < (uint)(_DAT_3ffc5174 - _DAT_3ffc5170 >> 5); uVar4 = uVar4 + 1) {
    FUN_400e8ca4(auStack_d0,_DAT_3ffc5170 + uVar4 * 0x20);
    if (((pcStack_cc != (code *)0x0) || (iStack_c0 != 0)) || (pcStack_b8 != (code *)0x0)) {
      if ((iStack_b4 == 0x28) || (iStack_b4 == *param_1)) {
        if (pcStack_cc == (code *)0x0) {
          if (iStack_c0 == 0) {
            (*pcStack_b8)(param_1);
          }
          else {
            aiStack_188[0] = *param_1;
            func_0x4008b3d8(auStack_b0,param_1 + 1,0x8c);
            (*pcStack_bc)(auStack_c8,aiStack_188,auStack_b0);
          }
        }
        else {
          (*pcStack_cc)();
        }
      }
    }
    (*(code *)&LAB_40183a17_1)(auStack_c8);
  }
LAB_400e8fb9:
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    (*(code *)&LAB_40183a17_1)(auStack_c8);
    thunk_FUN_401710d8(0);
  }
  return;
}

