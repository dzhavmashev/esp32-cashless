// Function : FUN_40170f54
// Address  : 0x40170f54
// Size     : 238 bytes


undefined8 FUN_40170f54(undefined4 *param_1)

{
  uint unaff_retaddr;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int aiStack_b0 [5];
  undefined4 uStack_9c;
  int iStack_98;
  int aiStack_78 [14];
  code *apcStack_40 [16];
  
  (*(code *)&SUB_40092e4c)();
  FUN_40170bac(aiStack_78,&stack0x00000000,unaff_retaddr & 0x3fffffff | 0x40000000);
  (*(code *)&SUB_4008b3d0)(aiStack_b0,aiStack_78);
  do {
    puVar1 = (undefined4 *)FUN_40170bfc(aiStack_b0,apcStack_40);
    puVar3 = puVar1;
    if (puVar1 == (undefined4 *)&DAT_00000005) {
LAB_40171040:
      return CONCAT44(puVar1,puVar3);
    }
    if (puVar1 != (undefined4 *)0x0) {
LAB_40170f98:
      puVar3 = (undefined4 *)0x3;
      puVar1 = puVar3;
      goto LAB_40171040;
    }
    if (apcStack_40[0] != (code *)0x0) {
      iVar2 = (*apcStack_40[0])(1,1,*param_1,param_1[1],param_1,aiStack_b0);
      if (iVar2 == 6) {
        param_1[4] = uStack_9c;
        param_1[3] = 0;
        (*(code *)&SUB_4008b3d0)(aiStack_b0,aiStack_78);
        puVar3 = (undefined4 *)FUN_40170e00(param_1,aiStack_b0,apcStack_40);
        if (puVar3 == (undefined4 *)&DAT_00000007) {
          iVar2 = 0;
          do {
            iVar5 = *(int *)((int)aiStack_78 + iVar2);
            iVar6 = *(int *)((int)aiStack_b0 + iVar2);
            puVar3 = puVar1;
            if (iVar5 != 0) {
              puVar3 = (undefined4 *)0x1;
            }
            if (((uint)(iVar6 != 0) & (uint)puVar3) != 0) {
              puVar3 = puVar1;
              if (iVar5 != iVar6) {
                puVar3 = (undefined4 *)0x1;
              }
              if (((uint)puVar3 & 0xff) != 0) {
                iVar4 = 0;
                do {
                  puVar3 = (undefined4 *)(iVar5 + iVar4);
                  *puVar3 = *(undefined4 *)(iVar6 + iVar4);
                  iVar4 = iVar4 + 4;
                } while (iVar4 != 0x10);
              }
            }
            iVar2 = iVar2 + 4;
          } while (iVar2 != 8);
          puVar1 = (undefined4 *)(iStack_98 * 4 + 2);
        }
        goto LAB_40171040;
      }
      if (iVar2 != 8) goto LAB_40170f98;
    }
    FUN_40170ddc(aiStack_b0,apcStack_40);
  } while( true );
}

