// Function : FUN_40116480
// Address  : 0x40116480
// Size     : 123 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40116480(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xfa;
  if ((((*param_2 & 0xf0) == 0xe0) && (*param_2 != _DAT_3ffc6480)) &&
     ((*(byte *)(param_1 + 0xeb) & 0x20) != 0)) {
    iVar1 = FUN_40116310(param_1,param_2);
    uVar2 = 0xff;
    if (iVar1 != 0) {
      if (*(char *)(iVar1 + 9) == '\0') {
        if ((*(char *)(iVar1 + 0xc) == '\0') && (*(code **)(param_1 + 0xf4) != (code *)0x0)) {
          (**(code **)(param_1 + 0xf4))(param_1,param_2,1);
        }
        FUN_40116154(param_1,iVar1,0x16);
        FUN_40116228(iVar1,5);
        *(undefined1 *)(iVar1 + 9) = 1;
        memw();
      }
      uVar2 = 0;
      *(char *)(iVar1 + 0xc) = *(char *)(iVar1 + 0xc) + '\x01';
      memw();
    }
  }
  memw();
  return uVar2;
}

