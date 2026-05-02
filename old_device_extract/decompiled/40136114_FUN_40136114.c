// Function : FUN_40136114
// Address  : 0x40136114
// Size     : 439 bytes


int FUN_40136114(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_38 [12];
  int aiStack_2c [11];
  
  iVar1 = FUN_40131ad8(param_2 + 0x18,1);
  if (iVar1 == 0) {
    iVar1 = FUN_401863d8(param_1);
    if (iVar1 == 2) {
      uVar2 = FUN_401317d8(param_2);
      if ((uVar2 <= param_1[0x17] + 7U >> 3) && (iVar1 = FUN_40131ad8(param_2,0), -1 < iVar1)) {
        iVar3 = *param_1;
        FUN_40186008(aiStack_2c);
        iVar1 = FUN_4013167c(aiStack_2c,param_2);
        param_1 = param_1 + 1;
        while (iVar1 == 0) {
          iVar1 = FUN_401860ec(aiStack_2c,param_1);
          if (iVar1 < 0) {
            iVar1 = FUN_40131ad8(aiStack_2c,1);
            if (((iVar1 < 1) ||
                ((iVar3 == 9 &&
                 ((iVar1 = FUN_401860ec(aiStack_2c,&DAT_3f41df74), iVar1 == 0 ||
                  (iVar1 = FUN_401860ec(aiStack_2c,"TEXT"), iVar1 == 0)))))) ||
               ((iVar1 = FUN_40131d48(aiStack_2c,aiStack_2c,1), iVar1 == 0 &&
                (iVar3 = FUN_401860ec(aiStack_2c,param_1), iVar3 == 0)))) {
              iVar1 = -0x4c80;
            }
            break;
          }
          iVar1 = FUN_40131d30(aiStack_2c,aiStack_2c,param_1);
        }
LAB_4013616c:
        FUN_40131548(aiStack_2c);
        return iVar1;
      }
    }
    else {
      if (iVar1 != 1) {
        return -0x4f80;
      }
      iVar1 = FUN_40131ad8(param_2,0);
      if (-1 < iVar1) {
        iVar3 = param_2 + 0xc;
        iVar1 = FUN_40131ad8(iVar3,0);
        if (-1 < iVar1) {
          piVar4 = param_1 + 1;
          iVar1 = FUN_401860ec(param_2,piVar4);
          if ((iVar1 < 0) && (iVar1 = FUN_401860ec(iVar3,piVar4), iVar1 < 0)) {
            FUN_40186008(auStack_38);
            FUN_40186008(aiStack_2c);
            iVar1 = FUN_40134f44(param_1,auStack_38,iVar3,iVar3);
            if ((iVar1 == 0) &&
               (iVar1 = FUN_40134f44(param_1,aiStack_2c,param_2,param_2), iVar1 == 0)) {
              if (param_1[6] == 0) {
                iVar1 = FUN_40131d74(aiStack_2c,aiStack_2c,3);
                while (iVar1 == 0) {
                  if ((-1 < aiStack_2c[0]) || (iVar1 = FUN_40131ad8(aiStack_2c,0), iVar1 == 0))
                  goto LAB_40136261;
                  iVar1 = FUN_40131d18(aiStack_2c,aiStack_2c,piVar4);
                }
              }
              else {
                iVar1 = FUN_40134f28(param_1,aiStack_2c,aiStack_2c,param_1 + 4);
                if (iVar1 == 0) {
LAB_40136261:
                  iVar1 = FUN_40134f44(param_1,aiStack_2c,aiStack_2c,param_2);
                  if ((iVar1 == 0) &&
                     (iVar1 = FUN_40134f28(param_1,aiStack_2c,aiStack_2c,param_1 + 7), iVar1 == 0))
                  {
                    iVar3 = FUN_401860ec(auStack_38,aiStack_2c);
                    iVar1 = 0;
                    if (iVar3 != 0) {
                      iVar1 = -0x4c80;
                    }
                  }
                }
              }
            }
            FUN_40131548(auStack_38);
            goto LAB_4013616c;
          }
        }
      }
    }
  }
  return -0x4c80;
}

