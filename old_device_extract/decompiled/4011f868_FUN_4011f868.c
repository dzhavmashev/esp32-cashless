// Function : FUN_4011f868
// Address  : 0x4011f868
// Size     : 115 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011f868(int *param_1,int *param_2)

{
  int iVar1;
  byte bVar2;
  undefined4 uVar3;
  
  uVar3 = 0x103;
  if ((_DAT_3ffc672c != 0) && (uVar3 = 0x102, param_1 != (int *)0x0)) {
    if ((*param_1 == 0) || (param_2 == (int *)0x0)) {
      uVar3 = 0x102;
    }
    else {
      uVar3 = 0x102;
      if (param_1[2] == 0) {
        iVar1 = (*(code *)&SUB_400841f0)(1,0x20,0x804);
        uVar3 = 0x101;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 0x10) = *param_1;
          *(int *)(iVar1 + 0x14) = param_1[1];
          bVar2 = 2;
          if ((char)param_1[4] == '\0') {
            bVar2 = 0;
          }
          *(byte *)(iVar1 + 0xf) = param_1[2] != 0 | bVar2;
          memw();
          *param_2 = iVar1;
          uVar3 = 0;
        }
      }
    }
  }
  memw();
  return uVar3;
}

