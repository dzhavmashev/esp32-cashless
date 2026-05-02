// Function : FUN_40161074
// Address  : 0x40161074
// Size     : 144 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40161074(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_40147fe4(6,1,3,0x3f4357ee);
  piVar1 = (int *)&DAT_3ffc7b1c;
  iVar2 = 0;
  do {
    if (*(char *)((int)piVar1 + 0x12) != '\0') {
      FUN_40147fe4(6,0x40,2,0x3f436ee1,iVar2);
      iVar3 = *piVar1;
      if (iVar3 != 0) {
        FUN_40147fe4(6,0x40,2,0x3f436eb6,iVar2,**(undefined4 **)(iVar3 + 0x2c));
        if ((**(uint **)(iVar3 + 0x2c) & 0x400000) == 0) {
          if (*(char *)(iVar3 + 0x1a) == '\x05') {
            iVar3 = *(int *)(_DAT_3ffc0034 +
                             (((*(uint **)(iVar3 + 0x2c))[4] >> 0x14 & 0xf) + 1) * 0x30 + 4);
            if (iVar3 != 0) goto LAB_401610dd;
          }
          else {
            FUN_4018a7b8(iVar3);
          }
        }
        else {
LAB_401610dd:
          FUN_40163b5c(iVar3);
        }
        *piVar1 = 0;
        *(undefined1 *)((int)piVar1 + 0x12) = 0;
        memw();
      }
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 9;
    if (iVar2 == 5) {
      memw();
      return 0;
    }
  } while( true );
}

