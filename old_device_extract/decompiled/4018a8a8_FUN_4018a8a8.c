// Function : FUN_4018a8a8
// Address  : 0x4018a8a8
// Size     : 108 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018a8a8(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2a4);
  if (_DAT_3ffca1fc != 0) {
    if (((DAT_3ffc1a44 != '\0') && (memw(), DAT_3ffc1a3c == '\0')) && (_DAT_3ffc1a40 != 0)) {
      return;
    }
    pcVar1 = *(code **)(_DAT_3ffc1a34 + 0xf8);
    uVar2 = _DAT_3ffca208;
    goto LAB_4018a911;
  }
  if (DAT_3ffc1a44 == '\0') {
LAB_4018a8e0:
    uVar2 = _DAT_3ffc0020;
  }
  else {
    memw();
    uVar2 = 3000000;
    if (DAT_3ffc1a3c != '\0') goto LAB_4018a8e0;
  }
  pcVar1 = *(code **)(_DAT_3ffc1a34 + 0xf8);
LAB_4018a911:
  (*pcVar1)(0x3ffca2a4,uVar2,0);
  return;
}

