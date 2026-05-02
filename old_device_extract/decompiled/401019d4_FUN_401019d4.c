// Function : FUN_401019d4
// Address  : 0x401019d4
// Size     : 419 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401019d4(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iStack_14c;
  undefined1 auStack_148 [292];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = (*(code *)&LAB_4018cf23_1)(param_1,param_2,param_3,param_4,param_5);
  iVar3 = iVar1;
  if (iVar1 != 0) goto LAB_40101a75;
  if (param_1 == _DAT_3ffbdea0) {
    iVar4 = 0xd;
    if (param_2 != 10) {
      iVar3 = 10;
      if (param_2 < 0xb) {
        iVar4 = param_2;
        if (param_2 != 4) {
          if (4 < param_2) goto LAB_40101a8e;
          iVar4 = 1;
          if (param_2 != 1) {
            if (param_2 < 2) {
              iVar4 = iVar1;
              if (param_2 != 0) goto LAB_40101a28;
            }
            else {
              iVar4 = 2;
              if (param_2 != 2) {
                iVar4 = 3;
                goto LAB_40101a4f;
              }
            }
          }
        }
      }
      else {
        iVar4 = 0x14;
        if (param_2 != 0x10) {
          if (param_2 < 0x11) {
            iVar4 = 0x10;
            if (param_2 != 0xd) {
              if (param_2 < 0xe) {
                iVar4 = 0xe;
                if ((param_2 != 0xb) && (iVar4 = 0xf, param_2 != 0xc)) goto LAB_40101a28;
              }
              else {
                iVar4 = 0x11;
                if (param_2 != 0xe) {
                  iVar3 = 0xf;
                  iVar4 = 0x12;
                  goto LAB_40101aa9;
                }
              }
            }
          }
          else {
            iVar4 = 0x15;
            if (param_2 != 0x13) {
              if (param_2 < 0x14) {
                iVar4 = 0x18;
                if (param_2 != 0x11) {
                  iVar3 = 0x12;
                  iVar4 = 9;
                  goto LAB_40101aa9;
                }
              }
              else {
                iVar4 = 0x16;
                if (param_2 != 0x14) {
                  iVar3 = 0x15;
                  iVar4 = 0x17;
                  goto LAB_40101aa9;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    if (param_1 != _DAT_3ffbde84) {
      uVar2 = (*(code *)&SUB_40094b80)();
      pcVar5 = " id %d\n";
      goto LAB_40101a3d;
    }
    iVar4 = 0x13;
    if (param_2 != 2) {
      if (param_2 < 3) {
        iVar4 = 7;
        if ((param_2 != 0) && (iVar4 = 8, param_2 != 1)) {
LAB_40101b32:
          uVar2 = (*(code *)&SUB_40094b80)();
          pcVar5 = " id %d\n";
          param_1 = param_2;
          goto LAB_40101a3d;
        }
      }
      else {
        iVar4 = 0x1e;
        if (((param_2 != 4) && (iVar4 = 0x19, 3 < param_2)) && (iVar4 = 0x1f, param_2 != 5))
        goto LAB_40101b32;
      }
    }
  }
LAB_40101a52:
  do {
    do {
      do {
        iStack_14c = iVar4;
        if (param_3 != 0) {
          memw();
          (*(code *)&SUB_4008b3d0)(auStack_148,param_3,param_4);
        }
        iVar3 = FUN_40184f18(&iStack_14c);
LAB_40101a75:
        param_3 = iStack_24;
        param_2 = _DAT_3ffc5708;
        memw();
        memw();
        if (iStack_24 == _DAT_3ffc5708) {
          return;
        }
        (*(code *)&SUB_40082ec4)();
LAB_40101a8e:
        iVar4 = iVar3;
      } while (param_2 == 7);
      if (7 < param_2) goto LAB_40101aa0;
      iVar4 = 5;
    } while (param_2 == 5);
    iVar4 = 6;
LAB_40101a4f:
  } while (param_2 == iVar4);
  goto LAB_40101a28;
LAB_40101aa0:
  iVar4 = 0xb;
  if (param_2 != 8) {
    iVar3 = 9;
    iVar4 = 0xc;
LAB_40101aa9:
    if (param_2 != iVar3) {
LAB_40101a28:
      uVar2 = (*(code *)&SUB_40094b80)();
      pcVar5 = "nt_send";
      param_1 = param_2;
LAB_40101a3d:
      FUN_4012113c(1,"oop_run",pcVar5,uVar2,"oop_run",param_1);
      iVar4 = 0x20;
    }
  }
  goto LAB_40101a52;
}

