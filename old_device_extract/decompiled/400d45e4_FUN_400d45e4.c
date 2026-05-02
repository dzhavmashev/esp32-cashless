// Function : FUN_400d45e4
// Address  : 0x400d45e4
// Size     : 64 bytes


undefined4 FUN_400d45e4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  do {
    uVar1 = (*(code *)&LAB_40183c7b_1)(param_1);
    if (uVar1 < 0xb) {
      if (uVar1 < 9) {
        if (uVar1 == 0) {
          uVar2 = 1;
          if (*(char *)(param_1 + 0x10) != '\0') {
            uVar2 = 2;
          }
        }
        else {
LAB_400d45fc:
          *(undefined1 *)(param_1 + 0x10) = 1;
          uVar2 = 0;
        }
        return uVar2;
      }
    }
    else if ((uVar1 != 0xd) && (uVar1 != 0x20)) goto LAB_400d45fc;
    *(undefined1 *)(param_1 + 0x1d) = 0;
  } while( true );
}

