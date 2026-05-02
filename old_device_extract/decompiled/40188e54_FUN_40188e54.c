// Function : FUN_40188e54
// Address  : 0x40188e54
// Size     : 244 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40188e54(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = FUN_401600d4(param_1);
  if ((iVar2 != 0) &&
     (((DAT_3ffc1a44 == '\0' || (memw(), DAT_3ffc1a3c != '\0')) ||
      (iVar2 = FUN_4018ba8c(), iVar2 != 0)))) {
    iVar2 = FUN_40188584(param_1);
    if (iVar2 != 0) {
      if ((**(uint **)(iVar2 + 0x2c) & 0x40000) != 0) {
        iVar3 = FUN_40189c90(*(undefined4 *)(iVar2 + 0x24));
        if ((iVar3 == 0) ||
           (iVar3 = FUN_40189ca4(*(undefined4 *)(iVar2 + 0x24),
                                 *(uint *)(*(int *)(iVar2 + 0x2c) + 4) & 0xf), iVar3 == 0)) {
          FUN_40163ab4(iVar2);
          iVar3 = *(int *)(iVar2 + 0x28);
          if (iVar3 != 0) {
            *(undefined4 *)(iVar2 + 0x28) = 0;
            *(undefined4 *)(*(int *)(iVar2 + 8) + 8) = 0;
            memw();
            iVar4 = iVar3;
            do {
              iVar6 = iVar4;
              *(undefined4 *)(*(int *)(iVar6 + 8) + 8) = 0;
              iVar1 = _DAT_3ffc0034;
              iVar4 = *(int *)(iVar6 + 0x28);
            } while (*(int *)(iVar6 + 0x28) != 0);
            iVar5 = _DAT_3ffc0034 + (*(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0x30;
            iVar4 = *(int *)(iVar5 + 0x20);
            *(int *)(iVar6 + 0x28) = iVar4;
            if (iVar4 == 0) {
              *(int *)(iVar5 + 0x24) = iVar6 + 0x28;
            }
            *(int *)(iVar1 + (*(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0x30 + 0x20)
                 = iVar3;
            *(undefined4 *)
             (iVar1 + ((*(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) >> 0x14 & 0xf) + 1) * 0x30 + 4) = 0
            ;
          }
        }
        else {
          iVar2 = FUN_40188b88(iVar2);
        }
      }
      memw();
      FUN_401883dc(iVar2);
      FUN_40187dd4(iVar2,param_1);
      return 0;
    }
    return 0xfffffffe;
  }
  return 0xffffffff;
}

