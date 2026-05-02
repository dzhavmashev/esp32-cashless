// Function : FUN_40135144
// Address  : 0x40135144
// Size     : 414 bytes


int FUN_40135144(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iStack_5c;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [12];
  undefined1 auStack_2c [44];
  
  if (param_3 < 2) {
    iVar1 = FUN_401350bc(param_1,*param_2);
  }
  else {
    iVar2 = FUN_4013ae30(param_3,0xc);
    iVar1 = -0x4d80;
    if (iVar2 != 0) {
      iVar3 = iVar2 + param_3 * 0xc;
      iVar1 = iVar2;
      do {
        memw();
        FUN_40186008(iVar1);
        iVar1 = iVar1 + 0xc;
      } while (iVar3 != iVar1);
      FUN_40186008(auStack_44);
      FUN_40186008(auStack_38);
      FUN_40186008(auStack_2c);
      iVar1 = FUN_4013167c(iVar2,*param_2 + 0x18);
      if (iVar1 == 0) {
        piVar4 = param_2 + 1;
        iVar5 = iVar2;
        do {
          memw();
          iVar1 = FUN_40134f44(param_1,iVar5 + 0xc,iVar5,*piVar4 + 0x18);
          if (iVar1 != 0) goto LAB_4013521d;
          piVar4 = piVar4 + 1;
          iVar5 = iVar5 + 0xc;
        } while (param_2 + param_3 != piVar4);
        iVar1 = FUN_40132650(auStack_44,iVar2 + param_3 * 0xc + -0xc,param_1 + 4);
        if (iVar1 == 0) {
          param_2 = param_2 + (param_3 - 1);
          do {
            param_3 = param_3 - 1;
            if (param_3 == 0) {
              iVar1 = FUN_4013167c(auStack_38,auStack_44);
            }
            else {
              iVar1 = FUN_40134f44(param_1,auStack_38,auStack_44,iVar2 + -0xc + param_3 * 0xc);
              if (iVar1 != 0) break;
              iVar1 = FUN_40134f44(param_1,auStack_44,auStack_44,*param_2 + 0x18);
            }
            if ((((iVar1 != 0) || (iVar1 = FUN_40134f44(param_1,auStack_2c,auStack_38), iVar1 != 0))
                || (iVar1 = FUN_40134f44(param_1,*param_2,*param_2,auStack_2c), iVar1 != 0)) ||
               (((iVar1 = FUN_40134f44(param_1,*param_2 + 0xc,*param_2 + 0xc,auStack_2c), iVar1 != 0
                 || (iVar1 = FUN_40134f44(param_1,*param_2 + 0xc,*param_2 + 0xc,auStack_38),
                    iVar1 != 0)) ||
                ((iVar1 = FUN_40131608(*param_2,*(undefined4 *)(param_1 + 8)), iVar1 != 0 ||
                 (iVar1 = FUN_40131608(*param_2 + 0xc,*(undefined4 *)(param_1 + 8)), iVar1 != 0)))))
               ) break;
            iVar5 = *param_2;
            param_2 = param_2 + -1;
            FUN_40131548(iVar5 + 0x18);
            if (param_3 == 0) break;
          } while( true );
        }
      }
LAB_4013521d:
      FUN_40131548(auStack_44);
      FUN_40131548(auStack_38);
      FUN_40131548(auStack_2c);
      iStack_5c = iVar2;
      do {
        FUN_40131548(iStack_5c);
        iStack_5c = iStack_5c + 0xc;
      } while (iVar3 != iStack_5c);
      memw();
      FUN_4013ae44(iVar2);
    }
  }
  return iVar1;
}

