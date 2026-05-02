// Function : FUN_401070d4
// Address  : 0x401070d4
// Size     : 221 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401070d4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (DAT_3ffc589d == '\0') {
    iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,2,&DAT_40106f50,0);
    if ((((((iVar2 == 0) &&
           (iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,3,0x40106e78,0), iVar2 == 0)) &&
          (iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,4,0x40106fa0,0), iVar2 == 0)) &&
         ((iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,5,0x40106f68,0), iVar2 == 0 &&
          (iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,0xc,0x40106f38,0), iVar2 == 0)))) &&
        ((iVar2 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbdea0,0xd,0x40106e60,0), iVar2 == 0 &&
         (iVar1 = (*(code *)&LAB_4018cec3_1)(_DAT_3ffbde84,0,0x40106f80,0), iVar2 = iVar1,
         iVar1 == 0)))) &&
       ((iVar2 = (*(code *)&LAB_4018ddef_1)(&DAT_401468a4), iVar2 == 0 || (iVar2 == 0x103)))) {
      DAT_3ffc589d = '\x01';
      memw();
    }
    else {
      iVar1 = iVar2;
      FUN_40107050();
    }
  }
  memw();
  return iVar1;
}

