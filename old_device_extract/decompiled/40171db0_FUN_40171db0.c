// Function : FUN_40171db0
// Address  : 0x40171db0
// Size     : 194 bytes


/* WARNING: Removing unreachable block (ram,0x40171e73) */
/* WARNING: Removing unreachable block (ram,0x40171e6d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40171db0(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint local_30 [12];
  
  (*(code *)&SUB_40082de4)(0x3ffc0770);
  for (puVar2 = _DAT_3ffc7ec0; puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[5]) {
    if (*puVar2 <= param_1) {
      iVar4 = FUN_4017188c(puVar2,param_1);
      goto LAB_40171e10;
    }
  }
  do {
    puVar2 = _DAT_3ffc7ec4;
    puVar3 = (uint *)&DAT_3ffc7ec0;
    if (_DAT_3ffc7ec4 == (uint *)0x0) {
      iVar4 = 0;
      break;
    }
    _DAT_3ffc7ec4 = (uint *)_DAT_3ffc7ec4[5];
    iVar4 = FUN_4017188c(puVar2,param_1);
    for (puVar5 = _DAT_3ffc7ec0; (puVar5 != (uint *)0x0 && (*puVar2 <= *puVar5));
        puVar5 = (uint *)puVar5[5]) {
      puVar3 = puVar5 + 5;
    }
    puVar2[5] = (uint)puVar5;
    *puVar3 = (uint)puVar2;
LAB_40171e10:
  } while (iVar4 == 0);
  (*(code *)&SUB_40082e0c)(0x3ffc0770);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    uVar6 = puVar2[4];
    *param_2 = puVar2[1];
    param_2[1] = puVar2[2];
    if ((uVar6 & 4) == 0) {
      uVar6 = uVar6 >> 3 & 0xff;
    }
    else {
      uVar6 = FUN_40171728(iVar4);
    }
    uVar1 = FUN_401713c4(uVar6 & 0xff,puVar2);
    FUN_40171410(uVar6 & 0xff,uVar1,iVar4 + 8,local_30);
    param_2[2] = local_30[0];
  }
  return iVar4;
}

