// Function : FUN_4013a498
// Address  : 0x4013a498
// Size     : 393 bytes


int FUN_4013a498(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  undefined1 auStack_2c [44];
  
  FUN_40186008(auStack_2c);
  memw();
  iStack_30 = param_2;
  iVar1 = FUN_40141738(&iStack_30,param_2 + param_3,&iStack_34,0x30);
  if (iVar1 == 0) {
    iVar3 = iStack_30 + iStack_34;
    iVar1 = FUN_4014180c(&iStack_30,iVar3,&iStack_38);
    if (iVar1 == 0) {
      if (iStack_38 != 0) {
        return -0x3d80;
      }
      uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c);
      if (((((((uVar2 == 0) && (uVar2 = FUN_4013b170(param_1,auStack_2c,0,0,0,0), uVar2 == 0)) &&
             (uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0)) &&
            ((uVar2 = FUN_4013b170(param_1,0,0,0,0,auStack_2c), uVar2 == 0 &&
             (uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0)))) &&
           ((uVar2 = FUN_4013b170(param_1,0,0,0,auStack_2c,0), uVar2 == 0 &&
            ((uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0 &&
             (uVar2 = FUN_4013b170(param_1,0,auStack_2c,0,0), uVar2 == 0)))))) &&
          (uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0)) &&
         (((((uVar2 = FUN_4013b170(param_1,0,0,auStack_2c,0,0), uVar2 == 0 &&
             (uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0)) &&
            (uVar2 = FUN_4013167c(param_1 + 0x44,auStack_2c), uVar2 == 0)) &&
           (((uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0 &&
             (uVar2 = FUN_4013167c(param_1 + 0x50,auStack_2c), uVar2 == 0)) &&
            ((uVar2 = FUN_4013a478(&iStack_30,iVar3,auStack_2c), uVar2 == 0 &&
             ((uVar2 = FUN_4013167c(param_1 + 0x5c,auStack_2c), uVar2 == 0 &&
              (uVar2 = FUN_4013b264(param_1), uVar2 == 0)))))))) &&
          ((uVar2 = FUN_4013b448(param_1), uVar2 == 0 && (iStack_30 != iVar3)))))) {
        uVar2 = 0xffffc29a;
      }
      FUN_40131548(auStack_2c);
      if (uVar2 == 0) {
        return 0;
      }
      if ((uVar2 & 0xff80) == 0) {
        iVar1 = uVar2 - 0x3d00;
      }
      else {
        iVar1 = -0x3d00;
      }
      FUN_4013c510(param_1);
      return iVar1;
    }
  }
  return iVar1 + -0x3d00;
}

