// Function : FUN_40172ad0
// Address  : 0x40172ad0
// Size     : 371 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_40172ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  uVar5 = FUN_40172c48(param_1,param_2,param_3,param_4);
  uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar1 = (undefined4)uVar5;
  if (_DAT_3ffc0774 == -1) {
    return uVar5;
  }
  iVar2 = (*(code *)&SUB_400637f4)(param_3,param_4,param_3,param_4);
  if (iVar2 != 0) {
    return uVar5;
  }
  iVar2 = (*(code *)&SUB_400637f4)(param_1,param_2);
  if (iVar2 == 0) {
    iVar2 = (*(code *)&SUB_400636a8)(param_1,param_2,0,0);
    if (iVar2 != 0) {
      iVar2 = FUN_40173828(uVar1,uVar4);
      if (((iVar2 == 0) && (iVar2 = FUN_40173828(param_1,param_2), iVar2 != 0)) &&
         (iVar2 = FUN_40173828(param_3,param_4), iVar2 != 0)) {
        iVar2 = (*(code *)&SUB_400637f4)(uVar1,uVar4,uVar1,uVar4);
        if (iVar2 != 0) {
          puVar3 = (undefined4 *)FUN_40173a8c();
          *puVar3 = 0x21;
          uVar5 = (*(code *)&SUB_40002954)(0,0);
          return uVar5;
        }
        puVar3 = (undefined4 *)FUN_40173a8c();
        *puVar3 = 0x22;
        iVar2 = (*(code *)&SUB_40063790)(param_1,param_2,0,0);
        if (iVar2 < 0) {
          uVar5 = FUN_40173848(param_3,param_4);
          iVar2 = (*(code *)&SUB_400636a8)
                            ((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),param_3,param_4);
          if (iVar2 != 0) {
            return 0xfff0000000000000;
          }
        }
        return 0x7ff0000000000000;
      }
      iVar2 = (*(code *)&SUB_400636a8)(uVar1,uVar4,0,0);
      if (iVar2 != 0) {
        return uVar5;
      }
      iVar2 = FUN_40173828(param_1,param_2);
      if (iVar2 == 0) {
        return uVar5;
      }
      iVar2 = FUN_40173828(param_3,param_4);
      if (iVar2 == 0) {
        return uVar5;
      }
      puVar3 = (undefined4 *)FUN_40173a8c();
      *puVar3 = 0x22;
      return 0;
    }
    iVar2 = (*(code *)&SUB_400636a8)(param_3,param_4,0,0);
    if (iVar2 != 0) {
      iVar2 = FUN_40173828(param_3,param_4);
      if (iVar2 == 0) {
        return uVar5;
      }
      iVar2 = (*(code *)&SUB_40063790)(param_3,param_4,0,0);
      if (-1 < iVar2) {
        return uVar5;
      }
      puVar3 = (undefined4 *)FUN_40173a8c();
      *puVar3 = 0x21;
      return 0xfff0000000000000;
    }
  }
  else {
    iVar2 = (*(code *)&SUB_400636a8)(param_3,param_4);
    if (iVar2 != 0) {
      return uVar5;
    }
  }
  return 0x3ff0000000000000;
}

